<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPIcs;

use PHPExiftool\Driver\AbstractTag;

class ParentReference3 extends AbstractTag
{

    protected $Id = 'TagStructureSubLabelsSubLabelsParentReference';

    protected $Name = 'ParentReference3';

    protected $FullName = 'XMP::ics';

    protected $GroupName = 'XMP-ics';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-ics';

    protected $g2 = 'Image';

    protected $Type = 'string';

    protected $Writable = true;

    protected $Description = 'Parent Reference 3';

    protected $flag_List = true;

}
