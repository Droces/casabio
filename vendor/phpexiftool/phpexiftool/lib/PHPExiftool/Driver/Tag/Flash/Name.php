<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Flash;

use PHPExiftool\Driver\AbstractTag;

class Name extends AbstractTag
{

    protected $Id = 'name';

    protected $Name = 'Name';

    protected $FullName = 'Flash::CuePoint';

    protected $GroupName = 'Flash';

    protected $g0 = 'Flash';

    protected $g1 = 'Flash';

    protected $g2 = 'Video';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Name';

}
