<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Leaf;

use PHPExiftool\Driver\AbstractTag;

class SharpObjName extends AbstractTag
{

    protected $Id = 'SharpObj_name';

    protected $Name = 'SharpObjName';

    protected $FullName = 'Leaf::Sharpness';

    protected $GroupName = 'Leaf';

    protected $g0 = 'Leaf';

    protected $g1 = 'Leaf';

    protected $g2 = 'Image';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Sharp Obj Name';

}
