<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\SVG;

use PHPExiftool\Driver\AbstractTag;

class ID extends AbstractTag
{

    protected $Id = 'id';

    protected $Name = 'ID';

    protected $FullName = 'XMP::SVG';

    protected $GroupName = 'SVG';

    protected $g0 = 'SVG';

    protected $g1 = 'SVG';

    protected $g2 = 'Image';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'ID';

}
